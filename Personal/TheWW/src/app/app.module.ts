import {BrowserModule} from '@angular/platform-browser';
import {NgModule} from '@angular/core';
import { AngularFireModule } from 'angularfire2';
import { AngularFireDatabaseModule } from 'angularfire2/database';
import { AngularFireAuthModule } from 'angularfire2/auth';
import { NgbModule } from '@ng-bootstrap/ng-bootstrap';

import {AppComponent} from './app.component';
import {RouterModule} from '@angular/router';
import {MyRoutes} from './app-routing.module';
import {GalleryService} from '../services/gallery.service';
import {environment} from '../environments/environment';
import {AngularFireStorageModule} from 'angularfire2/storage';
import { LoaderComponent } from './common/loader/loader.component';
import {BrowserAnimationsModule} from '@angular/platform-browser/animations';
import {MatButtonModule, MatCheckboxModule, MatProgressSpinnerModule} from '@angular/material';
import {GalleryComponent} from './pages/gallery/gallery.component';
import {CountryPageComponent} from './pages/country-page/country-page.component';
import {AboutComponent} from './pages/about/about.component';
import {HomeComponent} from './pages/home/home.component';
import {HttpClientModule} from '@angular/common/http';

@NgModule({
  declarations: [
    AppComponent,
    GalleryComponent,
    HomeComponent,
    AboutComponent,
    CountryPageComponent,
    LoaderComponent
  ],
  imports: [
    BrowserModule,
    RouterModule,
    MyRoutes,
    HttpClientModule,
    AngularFireModule.initializeApp(environment.firebase),
    AngularFireDatabaseModule,
    AngularFireStorageModule,
    AngularFireAuthModule,
    BrowserAnimationsModule,
    MatButtonModule,
    MatCheckboxModule,
    MatProgressSpinnerModule,
    NgbModule.forRoot()
  ],
  providers: [
    GalleryService,
  ],
  bootstrap: [AppComponent]
})
export class AppModule {
}
