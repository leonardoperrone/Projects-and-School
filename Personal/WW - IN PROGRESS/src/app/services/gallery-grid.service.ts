import { Injectable } from '@angular/core';
import { Http, Response } from '@angular/http';

import { Observable } from 'rxjs/Observable';
import 'rxjs/add/operator/do';
import 'rxjs/add/operator/catch';
import 'rxjs/add/operator/map';
import 'rxjs/add/observable/throw';

import { IGallery } from '../home/gallery-grid';

@Injectable()
export class GalleryGridService {
    private _imageUrl = 'assets/gallery.json';

    constructor(private _http: Http) {}

    getPictures(): Observable<IGallery[]> {
        return this._http.get(this._imageUrl)
            .map((response: Response) => <IGallery[]> response.json())
            .do(data => console.log('All: ' + JSON.stringify(data)))
            .catch(this.handleError);
    }

    getPicture(id: number): Observable<IGallery> {
        return this.getPictures()
            .map((pictures: IGallery[]) => pictures.find(p => p.pictureId === id));
    }

    private handleError(error: Response) {
        console.error(error);
        return Observable.throw(error.json().error || 'Server error');
    }
}
