import {BrowserModule} from '@angular/platform-browser';
import {NgModule} from '@angular/core';
import { AngularFireModule } from 'angularfire2';
import { AngularFireDatabaseModule } from 'angularfire2/database';
import { AngularFireAuthModule } from 'angularfire2/auth';
import { NgbModule } from '@ng-bootstrap/ng-bootstrap';

import {AppComponent} from './app.component';
import {GalleryComponent} from './gallery/gallery.component';
import {HomeComponent} from './home/home.component';
import {AboutComponent} from './about/about.component';
import {RouterModule} from '@angular/router';
import {MyRoutes} from './app-routing.module';
import {GalleryService} from '../services/gallery.service';
import {HttpModule} from '@angular/http';
import {environment} from '../environments/environment';
import {AngularFireStorageModule} from 'angularfire2/storage';
import { CountryPageComponent } from './country-page/country-page.component';

@NgModule({
  declarations: [
    AppComponent,
    GalleryComponent,
    HomeComponent,
    AboutComponent,
    CountryPageComponent
  ],
  imports: [
    BrowserModule,
    RouterModule,
    MyRoutes,
    HttpModule,
    AngularFireModule.initializeApp(environment.firebase),
    AngularFireDatabaseModule,
    AngularFireStorageModule,
    AngularFireAuthModule,
    NgbModule.forRoot()
  ],
  providers: [
    GalleryService,
  ],
  bootstrap: [AppComponent]
})
export class AppModule {
}
